
// Internal 
#include "user_config.h"
#include "partition.h"
#include "wifi.h"
#include "params.h" 
#include "fotabtn.h"

// SDK
#include <ets_sys.h>
#include <osapi.h>
#include <mem.h>
#include <user_interface.h>
#include <driver/uart.h>
#include <upgrade.h>
#include <c_types.h>
#include <ip_addr.h> 
#include <espconn.h>


static Params params;

void wifi_connect_cb(uint8_t status) {
	int i = 0;
    if(status == STATION_GOT_IP) {
		os_printf("Wifi Connected, Hello\r\n");
		os_printf("Hello World: %d\r\n", ++i);
		os_printf("Hello World: %d\r\n", ++i);
		os_printf("Hello World: %d\r\n", ++i);
    } else {
		os_printf("Wifi Disonnected\r\n");
    }
}


void user_init(void) {
    uart_init(BIT_RATE_115200, BIT_RATE_115200);
    os_delay_us(60000);
	//system_uart_swap();
	bool ok = params_load(&params);
	if (!ok) {
		os_printf("Cannot load Params, Trying to reset them.\r\n");
		if(!params_defaults(&params)) {
			os_printf("Cannot save params\r\n");
			return;
		}
	}

	os_printf("\r\nParams: name: %s, ssid: %s psk: %s ap-psk: %s\r\n",
			params.device_name,
			params.station_ssid, 
			params.station_psk,
			params.ap_psk
		);

    wifi_start(STATION_MODE, &params, wifi_connect_cb);
	fotabtn_init();
    os_printf("System started ...\r\n");
}


void ICACHE_FLASH_ATTR user_pre_init(void)
{
	//system_uart_swap();
    if(!system_partition_table_regist(at_partition_table, 
				sizeof(at_partition_table)/sizeof(at_partition_table[0]),
				SPI_FLASH_SIZE_MAP)) {
		os_printf("system_partition_table_regist fail\r\n");
		// HALT!
		while(1);
	}
}

