#ifndef WIFI_SECRET
#define WIFI_SECRET

  wifi_config_t sta_config = {
      .sta = {
          .ssid = CONFIG_WIFI_SSID_USER,
          .password = CONFIG_WIFI_PSK_USER,
          .bssid_set = false
      }
  };

#endif
