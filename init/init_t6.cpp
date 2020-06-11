/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <android-base/properties.h>
#include <android-base/logging.h>

#include "property_service.h"
#include "vendor_init.h"

using android::base::GetProperty;
using android::init::property_set;

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void property_override_triple(char const product_prop[], char const system_prop[], char const vendor_prop[], char const value[])
{
    property_override(product_prop, value);
    property_override(system_prop, value);
    property_override(vendor_prop, value);
}

void common_properties()
{
    property_set("rild.libargs", "-d /dev/smd0");
    property_set("rild.libpath", "/system/lib/libril-qc-qmi-1.so");
    property_set("vendor.rild.libpath", "/system/lib/libril-qc-qmi-1.so");
}

void cdma_properties(char const default_cdma_sub[], char const default_network[])
{
    property_override("ro.telephony.default_network", default_network);
    property_set("persist.radio.snapshot_enabled", "1");
    property_set("persist.radio.snapshot_timer", "22");
}

void gsm_properties(char const default_network[])
{
    property_override("ro.telephony.default_network", default_network);
    property_override("telephony.lteOnGsmDevice", "1");
}

void vendor_load_properties()
{
    std::string bootmid;
    std::string device;

    bootmid = GetProperty("ro.boot.mid", "");

    if (bootmid == "0P3P10000") {
        /* t6vzw (t6wl) */
        common_properties();
        cdma_properties("0", "8");
        property_override_triple("ro.product.model", "ro.product.system.model", "ro.product.vendor.model", "HTC6600LVW");
        property_override_triple("ro.build.fingerprint", "ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "VERIZON/HTCOneMaxVZW/t6wl:4.4.2/KOT49H/333209.2:user/release-keys");
        property_override("ro.build.description", "3.09.605.2 CL333209 release-keys");
        property_override_triple("ro.product.device", "ro.product.system.device", "ro.product.vendor.device", "t6vzw");
        property_override("ro.build.product", "t6vzw");
        property_set("ro.telephony.default_cdma_sub", "0");
        property_set("ro.ril.enable.sdr", "0");
        property_set("ro.ril.vzw.feature", "1");
        property_set("ro.ril.oem.ecclist", "911,*911,#911");
        property_set("ro.ril.enable.a52", "0");
        property_set("ro.ril.enable.a53", "1");
        property_set("ro.ril.enable.gea3", "1");
        property_set("ro.ril.disable.fd.plmn.prefix", "23402,23410,23411,23420");
        property_set("ro.ril.enable.managed.roaming", "1");
        property_set("ro.ril.oem.show.act", "0");
        property_set("ro.ril.set.mtusize", "1428");
        property_set("ro.ril.wp.feature", "1");
        property_set("telephony.lteOnCdmaDevice", "1");
        property_set("ro.cdma.data_retry_config", "max_retries=infinite,0,0,60000,120000,480000,900000");
        property_set("ro.gsm.data_retry_config", "max_retries=infinite,0,0,60000,120000,480000,900000");
        property_set("ro.gsm.2nd_data_retry_config", "max_retries=infinite,0,0,60000,120000,480000,900000");
        property_set("ro.config.svlte1x", "true");
        property_set("ro.telephony.get_imsi_from_sim", "true");
        property_set("ro.ril.def.agps.mode", "6");
    } else if (bootmid == "0P3P70000") {
        /* t6spr (t6whl) */
        common_properties();
        cdma_properties("1", "8");
        property_override_triple("ro.product.model", "ro.product.system.model", "ro.product.vendor.model", "One Max");
        property_override_triple("ro.build.fingerprint", "ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "htc/sprint_wwe/t6whl:4.4.2/KOT49H/335898.5:user/release-keys");
        property_override("ro.build.description", "3.02.651.5 CL335898 release-keys");
        property_override_triple("ro.product.device", "ro.product.system.device", "ro.product.vendor.device", "t6spr");
        property_override("ro.build.product", "t6spr");
        property_set("ro.telephony.default_cdma_sub", "1");
        property_set("telephony.sms.pseudo_multipart", "1");
        property_set("persist.radio.mode_pref_nv10", "1");
        property_set("persist.radio.dont_use_dsd", "true");
        property_set("ro.ril.set.mtusize", "1422");
        property_set("ro.ril.svdo", "true");
    } else if (bootmid == "0P3P40000") {
        /* t6tl */
        common_properties();
        property_override("ro.telephony.default_network", "22");
        property_override_triple("ro.product.model", "ro.product.system.model", "ro.product.vendor.model", "HTC 8088");
        property_override_triple("ro.build.fingerprint", "ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "htc/htccn_chs_cmcc/t6tl:5.0.2/LRX22G/524896.8:user/release-keys");
        property_override("ro.build.description", "3.22.1403.8 CL524896 release-keys");
        property_override_triple("ro.product.device", "ro.product.system.device", "ro.product.vendor.device", "t6tl");
        property_override("ro.build.product", "t6tl");
        property_set("ro.ril.enable.a52", "0");
        property_set("ro.ril.enable.a53", "1");
        property_set("ro.ril.hsdpa.category", "10");
        property_set("ro.ril.hsupa.category", "6");
        property_set("ro.ril.hsxpa", "2");
        property_set("ro.ril.enable.sdr", "0");
        property_set("ro.ril.set.mtusize", "1420");
        property_set("ro.ril.enable.r8fd", "1");
        property_set("ro.ril.disable.cpc", "1");
        property_set("ro.telephony.ipv6_capability", "1");
        property_set("ro.ril.enable.pre_r8fd", "1");
        property_set("ro.ril.fd.pre_r8_tout.scr_off", "2");
        property_set("ro.ril.fd.pre_r8_tout.scr_on", "3");
        property_set("ro.ril.fd.r8_tout.scr_off", "2");
        property_set("ro.ril.fd.r8_tout.scr_on", "3");
        property_set("ro.ril.td.hsxpa", "2");
        property_set("ro.ril.td.hsdpa.category", "15");
        property_set("ro.ril.td.hsupa.category", "6");
        property_set("ro.baseband.arch", "sglte2");
        property_set("persist.radio.tdscdma_present", "2");
        property_set("persist.radio.hyst_ps_to_g", "60");
    } else {
        /* t6 */
        common_properties();
        gsm_properties("22");
        property_override_triple("ro.product.model", "ro.product.system.model", "ro.product.vendor.model", "One Max");
        property_override_triple("ro.build.fingerprint", "ro.system.build.fingerprint", "ro.vendor.build.fingerprint", "htc/htc_europe/t6ul:5.0.2/LRX22G/525693.7:user/release-keys");
        property_override("ro.build.description", "4.13.401.7 CL525693 release-keys");
        property_override_triple("ro.product.device", "ro.product.system.device", "ro.product.vendor.device", "t6");
        property_override("ro.build.product", "t6");
    }

    device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootmid '" << bootmid.c_str() << "' setting build properties for '" << device.c_str() << "' device\n";
}
