# PassMaker

A simple password generator that can be used to generate passwords of any length. The password can be generated with or without special characters.

## Features

- Generate password of any given length
- Include custom amount of special characters
- Generate any amount of passwords at once
- Create groups in the password with custom length
- Use custom separator for the groups

## Installation

### Compile from source

- **Clone the repository**

```bash
git clone https://github.com/sgonsan/PassMaker
```

- **Navigate to the source code**

```bash
cd PassMaker
```

- **Compile the source code**

```bash
g++ -o passmaker code/passmaker.cpp
```

- **Run the program**

```bash.
./passmaker
```

## Usage

The program will ask for the length of the password, the amount of special characters, the amount of passwords to generate, the length of the groups and the separator for the groups.

The default values are:

- Length of password: 8
- Number of passwords: 1
- Number of special characters: 0
- Group size: 8 (complete password)
- Group divider: '-'

> [!IMPORTANT]
> The group divider will not be prompted if the group size is default, as it will not be used.

```output
Welcome to PassMaker!
Length of password to generate (default is 8): [8]
Number of passwords to generate (default is 1): [1]
Number of special characters to include (default is 0): [0]
Group size for passwords (default is 8): [8]

Generating 1 passwords of length 8 with 0 special characters and group size 8.

Rp1mSBFm
```

The group size can be used to create groups in the password. For example, if the size of the password is 16, the group size is 4 and the group divider is '-', the password will be generated as `abcd-efgh-ijkl-mnop`.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
