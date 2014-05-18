$(call inherit-product, vendor/cm/config/common_full_phone.mk)

$(call inherit-product, vendor/cm/config/nfc_enhanced.mk)

$(call inherit-product, device/htc/t6/full_t6.mk)

PRODUCT_BUILD_PROP_OVERRIDES += PRODUCT_NAME=htc_europe BUILD_ID=KOT49H BUILD_FINGERPRINT="htc/htc_europe/t6ul:4.4.2/KOT49H/338980.1:user/release-keys" PRIVATE_BUILD_DESC="3.12.401.1 CL338980 release-keys"

PRODUCT_NAME := cm_t6
PRODUCT_DEVICE := t6
