
reservedseating
===============
Reserved/Allocated/Assigned Seating for Venues and Events

![Build Status](https://mindpowered.dev/assets/images/github-badges/build-passing.svg)

Contents
========

* [Source Code and Documentation](#source-code-and-documentation)
* [Licensing](#licensing)
* [About](#about)
* [Requirements](#requirements)
* [Installation](#installation)
* [Usage](#usage)
* [Support](#support)

# Source Code and Documentation
- Source Code: [https://github.com/mindpowered/reserved-seating-cpp](https://github.com/mindpowered/reserved-seating-cpp)
- Documentation: [https://mindpowered.github.io/reserved-seating-cpp](https://mindpowered.github.io/reserved-seating-cpp)

# Licensing
To obtain a version of this package under the MIT License, follow the instructions to [get a license][purchase]. The MIT License has no restrictions on commercial use and permits reuse within proprietary software.

# About
Reserved seating is when each event ticket has a specific seat. That is, attendees will know where they will sit ahead of time. Seats are usually identified by row and seat using numbers or letters.

Venues may be set up for different types of events. In this case, the seating configuration, and seats available, will change.

Buying tickets for a reserved seating event can end in disappointment. Unless a system is in place that can hold a seat, they may sell out during the sale process. The system must also have a time limit on holds to make sure enough seats are available to buy. Holds should only last until the sale process is complete or expired. Expired holds should release the seats for sale again. Holds should only last long enough to complete the sale process.

This package aims to reserve seats for a venue and event and allow booking with holds that expire.

# Requirements
- Bazel - https://www.bazel.build/
- Haxe 4.1.1
- Neko
- hxcpp - https://lib.haxe.org/p/hxcpp/
- g++


Third-party dependencies may have additional requirements.

# Installation
Add rules to WORKSPACE file ...

```
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
  name = 'maglev',
  remote = 'https://github.com/mindpowered/maglev-cpp.git',
  branch = 'master',
)
git_repository(
  name = 'haxecpp',
  remote = 'https://github.com/mindpowered/haxecpp-cpp.git',
  branch = 'master',
)
git_repository(
  name = 'reservedseating',
  remote = 'https://github.com/mindpowered/reserved-seating-cpp.git',
  branch = 'master',
)
```

Reference dependency in BUILD file ...

```
    deps = [
        ...
        "@reservedseating//:reservedseating"
        ...
    ],
```


# Usage
```cpp
#include <mindpowered/reservedseating/ReservedSeating.h>

auto rs = new ReservedSeating();
rs->CreateVenue("123", "Venue 1", "250")
delete rs;
```


# Support
We are here to support using this package. If it doesn't do what you're looking for, isn't working, or you just need help, please [Contact us][contact].

There is also a public [Issue Tracker][bugs] available for this package.



[bugs]: https://github.com/mindpowered/reserved-seating-cpp/issues
[contact]: https://mindpowered.dev/support.html?ref=reserved-seating-cpp/
[docs]: https://mindpowered.github.io/reserved-seating-cpp/
[licensing]: https://mindpowered.dev/?ref=reserved-seating-cpp
[purchase]: https://mindpowered.dev/purchase/
