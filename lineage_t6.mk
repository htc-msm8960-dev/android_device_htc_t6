#
# Copyright (C) 2016 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Inherit some common Lineage stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)
$(call inherit-product, vendor/lineage/build/target/product/product_launched_with_j_mr2.mk)

$(call inherit-product, device/htc/t6/full_t6.mk)

## Device identifier. This must come after all inclusions
PRODUCT_DEVICE := t6
PRODUCT_NAME := lineage_t6

# Device Fingerprint
BUILD_FINGERPRINT := htc/htc_europe/t6ul:5.0.2/LRX22G/525693.7:user/release-keys
