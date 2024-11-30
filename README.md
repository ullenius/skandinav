# skandinav
Filter utility. Removes unwanted non-space UTF-8 characters from yaml, JSON and
other text-files.

* Allows ASCII and Swedish UTF-8 characters (ÅÄÖ åäö)

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
