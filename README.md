# skandinav
Filter utility. Removes unwanted UTF-8 characters from yaml, JSON and
other text-files.

## Allowed characters
* ASCII
* Swedish UTF-8 characters (ÅÄÖ åäö) 🇸🇪
* Danish/Norwegian UTF-8 characters (ÆØÅ æøå) 🇩🇰🇳🇴

* All other characters are ignored

```sh
usage: ./skandinav input.txt
```

For example:
```sh
$ ./skandinav application.yaml > filtered.yaml
```

## Building
Run:
```sh
./build.sh
```

## Requirements
C89

## Licence
GPL-3 only
