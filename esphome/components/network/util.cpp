#include "util.h"
#include "esphome/core/defines.h"
#ifdef USE_NETWORK
#ifdef USE_WIFI
#include "esphome/components/wifi/wifi_component.h"
#endif

#ifdef USE_ETHERNET
#include "esphome/components/ethernet/ethernet_component.h"
#endif

#ifdef USE_OPENTHREAD
#include "esphome/components/openthread/openthread.h"
#endif

namespace esphome {
namespace network {

bool is_connected() {
#ifdef USE_ETHERNET
  if (ethernet::global_eth_component != nullptr && ethernet::global_eth_component->is_connected())
    return true;
#endif

#ifdef USE_WIFI
  if (wifi::global_wifi_component != nullptr)
    return wifi::global_wifi_component->is_connected();
#endif

#ifdef USE_OPENTHREAD
  if (openthread::global_openthread_component != nullptr)
    return openthread::global_openthread_component->is_connected();
#endif

#ifdef USE_HOST
  return true;  // Assume its connected
#endif
  return false;
}

bool is_disabled() {
#ifdef USE_WIFI
  if (wifi::global_wifi_component != nullptr)
    return wifi::global_wifi_component->is_disabled();
#endif
  return false;
}

network::IPAddresses get_ip_addresses() {
#ifdef USE_ETHERNET
  if (ethernet::global_eth_component != nullptr)
    return ethernet::global_eth_component->get_ip_addresses();
#endif
#ifdef USE_WIFI
  if (wifi::global_wifi_component != nullptr)
    return wifi::global_wifi_component->get_ip_addresses();
#endif
#ifdef USE_OPENTHREAD
  if (openthread::global_openthread_component != nullptr)
    return openthread::global_openthread_component->get_ip_addresses();
#endif
  return {};
}

std::string get_use_address() {
#ifdef USE_ETHERNET
  if (ethernet::global_eth_component != nullptr)
    return ethernet::global_eth_component->get_use_address();
#endif
#ifdef USE_WIFI
  if (wifi::global_wifi_component != nullptr)
    return wifi::global_wifi_component->get_use_address();
#endif
  return "";
}

}  // namespace network
}  // namespace esphome
#endif
