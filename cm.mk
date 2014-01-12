$(call inherit-product, device/htc/t6/full_t6.mk)

$(call inherit-product, vendor/cm/config/nfc_enhanced.mk)

$(call inherit-product, vendor/cm/config/common_full_phone.mk)

PRODUCT_BUILD_PROP_OVERRIDES += PRODUCT_NAME=t6ul BUILD_ID=JSS15J BUILD_FINGERPRINT="htc/htc_europe/t6ul:4.3/JSS15J/259366.2:user/release-keys" PRIVATE_BUILD_DESC="1.19.401.2 CL259366 release-keys"

PRODUCT_NAME := cm_t6
PRODUCT_DEVICE := t6
