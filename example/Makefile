PF_MK ?=
ifeq ($(PF_MK), )
	FAKEVAR := $(info  Users shall select the platform at the first execution)
	PFNO := $(shell read -p "1. x86_64, 2. armv7_hf, 3. armv8_64 (type range: 1 ~ 3): " PF_MK; echo $$PF_MK)
	ifeq ($(PFNO), 3)
		PF_MK := armv8a_64_v2xcast
	else ifeq ($(PFNO), 2)
		PF_MK := armv7a_hf_v2xcast
	else ifeq ($(PFNO), 1)
		PF_MK := x86_64_v2xcast
	else
		FAKEVAR := $(info  Wrong characters)
		exit 1
	endif
	FAKEVAR := $(shell sed -i '1c PF_MK ?= $(PF_MK)' Makefile)
endif

ifeq ($(PF_MK), armv8a_64_v2xcast)
	CC := aarch64-linux-gnu-gcc-8
	EXTRA_CFLAGS := -std=gnu99 -Wall -Wextra

else ifeq ($(PF_MK), armv7a_hf_v2xcast)
	CC := arm-linux-gnueabihf-gcc
	EXTRA_CFLAGS := -std=gnu99 -Wall -Wextra -march=armv7-a -mfloat-abi=hard -mfpu=vfpv3-d16 -mthumb

else ifeq ($(PF_MK), x86_64_v2xcast)
	CC := gcc
	EXTRA_CFLAGS := -std=gnu99 -Wall -Wextra -fno-strict-aliasing -pipe -m64 -msse -msse2 -D__X86__
endif

INC_PATH ?= $(realpath ../inc)
LIB_PATH ?= $(realpath ../lib)
LIBS ?= -leu_v2xcast -pthread -lrt -lm -lzmq
CFLAGS += $(EXTRA_CFLAGS) -Werror-implicit-function-declaration
export CFLAGS INC_PATH LIB_PATH LIBS CC

EXAMPLES := itsmsg v2xcast_cam v2xcast_denm v2xcast_rtcmem v2xcast_event_detector_eu v2xcast_spatem_generator v2xcast_mapem v2xcast_multiple_subscrible_eu v2xcast_traffic_signal_detector_eu v2xcast_ivim v2xcast_txrx_eu v2xcast_rawdata_eu v2xcast_mgnt_coexistence_mode_eu v2xcast_static_memory_usage_eu v2xcast_tlc v2xcast_saem v2xcast_vam
SUBDIRS := libitsmsg v2xcast_cam v2xcast_denm v2xcast_rtcmem v2xcast_event_detector_eu v2xcast_spatem_generator v2xcast_mapem v2xcast_multiple_subscrible_eu v2xcast_traffic_signal_detector_eu v2xcast_ivim v2xcast_txrx_eu v2xcast_rawdata_eu v2xcast_mgnt_coexistence_mode_eu v2xcast_static_memory_usage_eu v2xcast_tlc v2xcast_saem v2xcast_vam

.PHONY: all $(EXAMPLES)

all: $(EXAMPLES)

reset:
	 @sed -i '1c PF_MK ?= ' Makefile;
	 @echo Configuration has been reset!

itsmsg:
	make -C libitsmsg

v2xcast_cam:
	make -C v2xcast_cam

v2xcast_denm:
	make -C v2xcast_denm

v2xcast_rtcmem:
	make -C v2xcast_rtcmem

v2xcast_event_detector_eu:
	make -C v2xcast_event_detector_eu

v2xcast_spatem_generator:
	make -C v2xcast_spatem_generator

v2xcast_mapem:
	make -C v2xcast_mapem

v2xcast_multiple_subscrible_eu:
	make -C v2xcast_multiple_subscrible_eu

v2xcast_ivim:
	make -C v2xcast_ivim

v2xcast_traffic_signal_detector_eu:
	make -C v2xcast_traffic_signal_detector_eu

v2xcast_txrx_eu:
	make -C v2xcast_txrx_eu

v2xcast_rawdata_eu:
	make -C v2xcast_rawdata_eu

v2xcast_mgnt_coexistence_mode_eu:
	make -C v2xcast_mgnt_coexistence_mode_eu

v2xcast_static_memory_usage_eu:
	make -C v2xcast_static_memory_usage_eu

v2xcast_tlc:
	make -C v2xcast_tlc

v2xcast_saem:
	make -C v2xcast_saem

v2xcast_vam:
	make -C v2xcast_vam

clean:
	$(foreach d, $(SUBDIRS), make -C $(d) clean;)
