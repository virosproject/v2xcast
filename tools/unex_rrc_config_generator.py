#!/usr/bin/env python3

from __future__ import print_function
from binascii import hexlify
from os.path import exists
import asn1tools
import sys, getopt

channel_mapping_tbl_10MHz = [\
    ['172', '5860', '54590'],\
    ['174', '5870', '54690'],\
    ['176', '5880', '54790'],\
    ['178', '5890', '54890'],\
    ['180', '5900', '54990'],\
    ['182', '5910', '55090'],\
    ['184', '5920', '55190']]

channel_mapping_tbl_20MHz = [\
    ['173', '5865', '54640'],\
    ['175', '5875', '54740'],\
    ['181', '5910', '55040'],\
    ['183', '5915', '55140']]

BW_List = ['n1', 'n3', 'n5', 'n8', 'n10', 'n15', 'n20']
Power_Range = [-30, 33]

def show_help_msg():
    print('Usage:')
    print('unex_rrc_config_generator.py --action [-f <earfcn>] [-b <bandwidth>] [-o <output_file>]')
    print('Actions are:')
    print('  get\tGet the current information.')
    print('\tEx: ./unex_rrc_config_generator.py --get')
    print('  set\tSet the frequency and generate new rrc config file.')
    print('\tEx: ./unex_rrc_config_generator.py --set -f 55140 -b 20 -o new_cv2x_rrc_config.uper')
    print('\n\t====== Channel Mapping Table ======')
    print('\t Ch\t Radio Freq\t Earfcn')
    for info in channel_mapping_tbl_10MHz:
        print('\t', info[0], '\t', info[1], '/ 10MHz\t', info[2])
    print()
    for info in channel_mapping_tbl_20MHz:
        print('\t', info[0], '\t', info[1], '/ 20MHz\t', info[2])
    print()

def check_value_in_list(arg, check_list):
    if arg not in check_list:
        return 0
    else:
        return 1

def check_value_range(arg, lower, upper):
    if arg < lower or arg > upper:
        print('Input Value is invalid.')
        print('Valid range: from', lower, 'to', upper)
        sys.exit();

def get_freq_list(freq_List):
    for i in range(len(channel_mapping_tbl_10MHz)):
        freq_List += [channel_mapping_tbl_10MHz[i][2]]
    for i in range(len(channel_mapping_tbl_20MHz)):
        freq_List += [channel_mapping_tbl_20MHz[i][2]]

def get_10M_freq_list(freq_List):
    for i in range(len(channel_mapping_tbl_10MHz)):
        freq_List += [channel_mapping_tbl_10MHz[i][2]]

def get_20M_freq_list(freq_List):
    for i in range(len(channel_mapping_tbl_20MHz)):
        freq_List += [channel_mapping_tbl_20MHz[i][2]]

def check_freq_valid(freq):
    freq_List_10M = []
    get_10M_freq_list(freq_List_10M)
    res_10M = check_value_in_list(freq, freq_List_10M)
    freq_List_20M = []
    get_20M_freq_list(freq_List_20M)
    res_20M = check_value_in_list(freq, freq_List_20M)
    if res_10M == 1:
        bandwidth = 10
    elif res_20M == 1:
        bandwidth = 20
    else:
        bandwidth = 0
        print('Input Value is invalid, freq =', freq)
    return bandwidth

def rrc_config_decode(asn1_file, rrc_config_file):
    asn_file_exists = exists(asn1_file)
    rrc_config_file_exists = exists(rrc_config_file)
    if asn_file_exists == True and rrc_config_file_exists == True:
        rrc_config = asn1tools.compile_files(asn1_file, 'uper')
        rrc_config_uper_file = open(rrc_config_file, 'rb')
        rrc_config_uper_content = rrc_config_uper_file.read()
        # print('type of rrc_config_uper_content:', type(rrc_config_uper_content))
        # print('rrc_config_uper_content =', rrc_config_uper_content.hex())
        decoded = rrc_config.decode('SL-V2X-Preconfiguration-r14', rrc_config_uper_content)
        # print('type of decoded = ', type(decoded))
        # print('Decoded:', decoded)
        return decoded
    else:
        print('Please make sure the asn file (', asn1_file,') and rrc configuration file (', rrc_config_file, ') exist!')
        sys.exit()

def get_decoded_rrc_config(asn1_file, rrc_config_file):
    decoded = rrc_config_decode(asn1_file, rrc_config_file)
    freq = decoded['v2x-PreconfigFreqList-r14'][0]['v2x-CommPreconfigGeneral-r14']['carrierFreq-r12']
    num_of_PRB = int(decoded['v2x-PreconfigFreqList-r14'][0]['v2x-CommPreconfigGeneral-r14']['sl-bandwidth-r12'][1:])
    if num_of_PRB == 100:
        bw = 20
    elif num_of_PRB == 50:
        bw = 10
    print('carrierFreq:', freq, ', bandwidth:', str(bw), "MHz")

def set_decoded_rrc_config(asn1_file, rrc_config_file, set_freq, set_bw):
    decoded = rrc_config_decode(asn1_file, rrc_config_file)
    # sizeSubchannel: number of PRBs of each subchannel, 1 PRB = 180kHz
    # numSubchannel: number of subchannels in the corresponding resource pool
    sizeSubchannel = int(decoded['v2x-PreconfigFreqList-r14'][0]['v2x-CommRxPoolList-r14'][0]['sizeSubchannel-r14'][1:])
    freq_List = []
    if set_bw == 20:
        get_20M_freq_list(freq_List)
        num_of_PRB = 100
    elif set_bw == 10:
        get_10M_freq_list(freq_List)
        num_of_PRB = 50
    else:
        print('error: bandwidth =', set_bw, 'is not support')
        sys.exit()

    find = check_value_in_list(set_freq, freq_List)
    if find == 0:
        print("can't find freq", set_freq, "in", set_bw, "MHz list")
        sys.exit()
    else:
        numSubchannel = int(num_of_PRB / sizeSubchannel)
        print('bandwidth =', set_bw, 'MHz, sizeSubchannel =', sizeSubchannel, ', numSubchannel =', numSubchannel)

    decoded['v2x-PreconfigFreqList-r14'][0]['v2x-CommPreconfigGeneral-r14']['carrierFreq-r12'] = int(set_freq)
    decoded['v2x-PreconfigFreqList-r14'][0]['v2x-CommRxPoolList-r14'][0]['numSubchannel-r14'] = 'n%d' % numSubchannel
    decoded['v2x-PreconfigFreqList-r14'][0]['v2x-CommTxPoolList-r14'][0]['numSubchannel-r14'] = 'n%d' % numSubchannel
    decoded['v2x-PreconfigFreqList-r14'][0]['v2x-CommPreconfigGeneral-r14']['sl-bandwidth-r12'] = 'n%d' % num_of_PRB
    print('Change carrierFreq to', decoded['v2x-PreconfigFreqList-r14'][0]['v2x-CommPreconfigGeneral-r14']['carrierFreq-r12'])
    print('Change rx pool numSubchannel to', decoded['v2x-PreconfigFreqList-r14'][0]['v2x-CommRxPoolList-r14'][0]['numSubchannel-r14'])
    print('Change tx pool numSubchannel to', decoded['v2x-PreconfigFreqList-r14'][0]['v2x-CommTxPoolList-r14'][0]['numSubchannel-r14'])
    print('Change comm pool bandwidth to', decoded['v2x-PreconfigFreqList-r14'][0]['v2x-CommPreconfigGeneral-r14']['sl-bandwidth-r12'])
    return decoded

def rrc_config_encode(asn1_file, output_uper_file, decoded):
    asn_file_exists = exists(asn1_file)
    if asn_file_exists == True:
        rrc_config = asn1tools.compile_files(asn1_file, 'uper')
        # print('Decoded:', decoded)
        encoded_rrc_config = rrc_config.encode('SL-V2X-Preconfiguration-r14', decoded)
        # print(encoded_rrc_config.hex())
        output_rrc_config_uper_file = open(output_uper_file, 'wb')
        output_rrc_config_uper_file.write(encoded_rrc_config)
        output_rrc_config_uper_file.close()
        print('Generate rrc config in', output_uper_file)
    else:
        print('Please make sure the asn file (', asn1_file,')!')
        sys.exit()

def main(argv):
    try:
    	opts, args = getopt.getopt(argv,"hf:b:o:",["get","set"])
    except:
        print('Please try \"unex_rrc_config_generator.py -h\" for more information.')
        sys.exit(2)

    # rrc config asn file
    asn1_file = '3GPP_RRC_v14.8.0.asn'
    # rrc config uper file
    rrc_config_file = 'cv2x_rrc_config.uper'
    set_params = 0
    output_uper_file = ''

    for opt, arg in opts:
        if opt == '-h':
            show_help_msg()
            sys.exit()
        elif opt == '--get':
            get_decoded_rrc_config(asn1_file, rrc_config_file)
            sys.exit()
        elif opt == '--set':
            set_params = 1
            if len(opts) <= 1:
                print('No input paramters for setting.')
                print('Please try \"unex_rrc_config_generator.py -h\" for more information.')
                sys.exit()
        elif opt == '-f' and set_params == 1:
            set_freq = arg
        elif opt == '-b' and set_params == 1:
            set_bw = arg
        elif opt == '-o' and set_params == 1:
            output_uper_file = arg

    if set_params == 1:
        if not output_uper_file:
            print('Failed: No output file name.')
            sys.exit()
        new_decoded_rrc_config = set_decoded_rrc_config(asn1_file, rrc_config_file, set_freq, int(set_bw))
        rrc_config_encode(asn1_file, output_uper_file, new_decoded_rrc_config)

if __name__ == "__main__":
    if len(sys.argv) <= 1:
        print('Please try \"unex_rrc_config_generator.py -h\" for more information.')
        sys.exit()

    main(sys.argv[1:])