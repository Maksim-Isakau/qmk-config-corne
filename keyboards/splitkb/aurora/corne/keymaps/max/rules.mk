# Target the Adafruit KB2040 (RP2040) via QMK's Pro Micro converter.
CONVERT_TO = kb2040

# Caps Word (CW_TOGG on the na1 layer).
CAPS_WORD_ENABLE = yes

# Keep the first build lean and reliable on RP2040 — these are off in the ZMK
# config too. Flip any to `yes` later to enable.
RGB_MATRIX_ENABLE = no
OLED_ENABLE = no
ENCODER_ENABLE = no
