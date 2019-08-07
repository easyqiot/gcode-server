#include <osapi.h>
#include <c_types.h>
#include <user_interface.h>

#include "params.h"


bool ICACHE_FLASH_ATTR 
params_save(Params* params) {
	params->magic = MAGIC;
	return system_param_save_with_protect(PARAMS_SECTOR, params, 
			sizeof(Params));
}


bool ICACHE_FLASH_ATTR 
params_load(Params* params) {
	bool ok = system_param_load(PARAMS_SECTOR, 0,
			params, sizeof(Params));
	return ok && params->magic == MAGIC;
}


bool ICACHE_FLASH_ATTR 
params_defaults(Params* params) {
	os_sprintf(params->device_name, "NewDevice");
	params->ap_psk[0] = 0;
	params->station_ssid[0] = 0;
	params->station_psk[0] = 0;
	return params_save(params);
}

