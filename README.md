# BranchPrediction

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
    </li>
    <li>
	<a href="#usage">Usage</a>
    	<ul>
		<li><a href="#input-format">Input Format</a></li>
		<li><a href="#clean-project">Clean Project</a></li>
		<li><a href="#example">Example</a></li>
	</ul>
    </li>
    <li>
      <a href="#testing-on_eustis-3">Testing on Eustis 3</a>
    </li>
    <li><a href="#license">License</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

# About the Project

This is a C++ program that simulates a **branch predictor** and designs **branch predictors**.

# Getting Started

To get started you must have `g++` installed to run this program.

To install the G++ compiler on Linux run:

```bash
sudo apt install g++
```

Verify that you have `g++`:

```
g++ --version
```

The `Makefile` also runs memory leak detection using `valgrind`. To install valgrind:

```
sudo apt install valgrind
```

# Usage

To compile the program run:

```bash
make
```

## Input Format

After running `make`, to run the executable enter the following commands to run each predictor:

### Smith n-bit Counter Predictor

```bash
./sim smith <B> <tracefile>
```

-   **B**:
    -   `unsigned int`
    -   The number of counter bits used for prediction.

### Bimodal Predictor

```bash
./sim bimodal <M2> <tracefile>
```

-   **M2**
    -   `unsigned int`
    -   The number of PC bits used to index the bimodal table.

### GShare Predictor

```bash
./sim gshare <M1> <N> <tracefile>
```

-   **M1**
    -   `unsigned int`
    -   Number of PC bits used with **N** (global branch history) register bits to index the gshare table.

### Hybrid Predictor

```bash
./sim hybrid <K> <M1> <N> <M2> <tracefile>
```

-   **K**
    -   The number of PC bits used to index the chooser table.

### Remaining Input Arguments

-   **N**

    -   `unsigned int`
    -   The number of global branch history register bits used with **M1** PC bits to index the gshare table.

-   **tracefile**
    -   `std::string`
    -   Full name of trace file including any extension.

## Clean Project

After running `make` and `./sim`, clean the project:

```bash
make clean
```

To force clean, run:

```bash
make clobber
```

## Example

# Testing on Eustis 3

To connect to eustis 3:

```bash
YOUR_NID@eustis3.eecs.ucf.edu
```

Enter your NID password and then run:

```bash
cd BranchPrediction/
make
./sim [with parameters]
```

## Getting Project Folder

Before logging into eustis 3, transfer the project folder:

```bash
scp -r BranchPrediction/ YOUR_NID@eustis3.eecs.ucf.edu:~/
```

Then, enter you credentials.

OR

Clone the project from GitHub:

```bash
git clone https://github.com/stefanwerleman/BranchPrediction.git

cd BranchPrediction/
```

# License

Distributed under the MIT License. See `LICENSE` for more information.

# Acknowledgments

-   [The Pitchfork Layout](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs)

-   **spdlog: C++ Logger**
    -   [Home Page](https://spdlog.docsforge.com/master/)
    -   [GitHub](https://github.com/gabime/spdlog)
