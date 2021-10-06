# Owodunni planck layout

By Alexander Poole

## Main idea

This is a balanced QWERTY layout that is made for typing and coding.
It is inspired by [BEAKL-27](https://ieants.cc/beakl/layouts.phpq) for
the symbol layers. It keeps [colemak-dh](https://colemakmods.github.io/mod-dh/)
if I ever decide to learn it.

## Build

To build:
```cli
qmk compile -kb planck/rev6_drop -km owodunni
```

Or first configure QMK:
```cli
qmk config user.keyboard=planck/rev6_drop
```
```cli
qmk config user.keymap=owodunni
```
Then you can compile without flags:
```cli
qmk compile
```

## Swedish keys

To write Swedish use the following keys while using a Swedish keymap:

| SE key | US key |
|--------|--------|
| å      |  [     |
| ä      |  '     |
| ö      |  ;     |
