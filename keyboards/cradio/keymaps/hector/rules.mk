
SRC += features/achordion.c
SRC += features/select_word.c
SRC += features/sentence_case.c

# if firmware size over limit, try this option
LTO_ENABLE = yes

DYNAMIC_MACRO_ENABLE = yes
TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
AUTOCORRECT_ENABLE = yes
REPEAT_KEY_ENABLE = yes
COMMAND_ENABLE = no
