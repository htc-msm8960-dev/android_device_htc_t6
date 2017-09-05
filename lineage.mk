$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

$(call inherit-product, device/htc/t6/full_t6.mk)

PRODUCT_BUILD_PROP_OVERRIDES += PRODUCT_NAME=htc_europe BUILD_ID=LRX22G BUILD_FINGERPRINT="htc/htc_europe/t6ul:5.0.2/LRX22G/525693.7:user/release-keys" PRIVATE_BUILD_DESC="4.13.401.7 CL525693 release-keys"

PRODUCT_NAME := lineage_t6
PRODUCT_DEVICE := t6
