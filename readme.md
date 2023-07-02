# Quantum Mechanical Keyboard Firmware

Please note this firmware is still a work in progress as of Jul-1-2023.
- [ ] currently working on making customization easier
- [ ] working on buttoning up the RGB lighting options and configuration

This is a fork of the [QMK Firmware](https://github.com/qmk/qmk_firmware), modified for the [Sofle RGB v2.1 Keyboard](https://josefadamcik.github.io/SofleKeyboard/) created by Josef Adamcik with the RGB version reliant on contributions by Dane Evans. Support for both Pro Micro and Elite-C controller types. Extra features include OLED screen animations and WPM counter, better lighting control and customization, and proper [VIA](https://usevia.app/) support. The code base for this keyboard was also designed with ease of modifications and customization in mind.

## Documentation

* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are powered by [Docsify](https://docsify.js.org/) and hosted on [GitHub](/docs/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls), or by clicking the "Edit this page" link at the bottom of any page.

## Keyboard

* [Sofle](/keyboards/sofle/) - Original QMK Sofle Keyboard firmware
* [Sofle RGB v2.1](/keyboards/starvore/sofle) - Modified Sofle QMK firmware built specifically for the Sofle RGB v2.1 (although slight modifications can be used to make it work for other versions)

## Building and flashing

To build the firmware, make sure you have QMK properly setup on your development machine. Next, simply run the following command to compile and flash the firmware to your keyboard's controller. You will need to do this for each half of the Sofle keyboard.

```sh
qmk flash -kb starvore/sofle -km via
```

To compile the firmware without flashing, simply run:

```sh
qmk compile -kb starvore/sofle -km via
```

## Customization

TODO: Finish Writing 'customization' section

### Firmware Customization

Most customization options exist within the file [keymap.h](/keyboards/starvore/sofle/keymaps/via/keymap.c) within the VIA keymap folder. Use this file to change things like RGB lighting, layer names, and OLED screen options. 

### Keymap Customization

To edit the keymap, simply edit the [keymap.c](/keyboards/starvore/sofle/keymaps/via/keymap.c) file. If using [VIA](https://usevia.app/), (enabled by default) you can go to [usevia.app](https://usevia.app/) using a Chromium based browser to use a web GUI to edit your keymaps in real time. You can then save these keymaps as a JSON file for backups.

## Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to original QMK Git repo page, the documentation, and the keyboards supported by QMK.
