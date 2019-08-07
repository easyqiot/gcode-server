#ifndef _PARAMS_H__
#define _PARAMS_H__

#include "c_types.h"
#include "partition.h"

#define PARAMS_SECTOR SYSTEM_PARTITION_PARAMS_ADDR / 4096 

#define MAGIC 'I'

typedef struct {
	 char device_name[16];
	 char ap_psk[32];
	 char station_ssid[32];
	 char station_psk[32];
	 char magic;
} Params;


bool ICACHE_FLASH_ATTR 
params_save(Params* params);

bool ICACHE_FLASH_ATTR 
params_load(Params* params);

#endif

