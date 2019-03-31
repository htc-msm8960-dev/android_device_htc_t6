$(call inherit-product, vendor/rr/config/common_full_phone.mk)

$(call inherit-product, device/htc/t6/full_t6.mk)

PRODUCT_NAME := rr_t6
PRODUCT_DEVICE := t6

# Device Fingerprint
BUILD_FINGERPRINT := htc/htc_europe/t6ul:5.0.2/LRX22G/525693.7:user/release-keys