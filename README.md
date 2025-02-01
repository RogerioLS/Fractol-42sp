<div align = center>

# :clipboard: Fractol | 42 SP

![Norminette](https://github.com/RogerioLS/Fractol-42sp/actions/workflows/norminette.yml/badge.svg)
![Build](https://github.com/RogerioLS/Fractol-42sp/actions/workflows/build.yml/badge.svg)
![Static Badge](https://custom-icon-badges.demolab.com/badge/FRACTOL-42-blue?logo=repo)
![42 São Paulo](https://custom-icon-badges.demolab.com/badge/42-SP-1E2952)
![License](https://custom-icon-badges.demolab.com/github/license/RogerioLS/Fractol-42sp?logo=law&color=dark-green)
![Code size in bytes](https://custom-icon-badges.demolab.com/github/languages/code-size/RogerioLS/Fractol-42sp?logo=file-code&color=dark-green)
![Top language](https://custom-icon-badges.demolab.com/github/languages/top/RogerioLS/Fractol-42sp?color=dark-green)
![Last commit](https://custom-icon-badges.demolab.com/github/last-commit/RogerioLS/Fractol-42sp?logo=history&color=dark-green)
![Repo size](https://custom-icon-badges.demolab.com/github/repo-size/RogerioLS/Fractol-42sp?logo=database)
![Languages](https://custom-icon-badges.demolab.com/github/languages/count/RogerioLS/Fractol-42sp?logo=command-palette&color=red)
![GitHub repo file count (file type)](https://custom-icon-badges.demolab.com/github/directory-file-count/RogerioLS/Fractol-42sp%2Fsources?logo=file&label=files%20sources&color=8602b1)
![Discord](https://custom-icon-badges.demolab.com/discord/1114673462859006044?&logo=comments&label=testemunhas%20de%20vim&color=ffbe3a)
![](https://img.shields.io/github/forks/RogerioLS/Fractol-42sp)

</div>

---

<div align = center>

![](https://game.42sp.org.br//static/assets/achievements/fract-olm.png)

</div>

- Actual Status : finished.
- Result        : Approved with 120 points ✅

## 📜 About Project

> One of the first graphical projects at 42 School, fract-ol generates beautiful fractals from the complex numbers of \
> an iterative mathematical construct. A fractal is a fragmented geometrical figure that infinitely repeats itself at \
> smaller scales. This project uses the school's graphical library, MiniLibX.

For detailed information, refer to the [**subject of this project**](README_files/fractol_subject.pdf).

	🚀 TLDR: The fract-ol project is one of the three "beginner" graphical projects of the 
 		 cursus. It teaches you about using graphic library, advanced math, and more.

## 📑 Fractals List

The program supports these fractal sets:

| Name              | Formula                                                                                            |
|:-----------------:|:--------------------------------------------------------------------------------------------------:|
| Mandelbrot        | $z_{n+1} = z_n^2 + c, z_0 = 0$                                                                     |
| Julia             | $z_{n+1} = z_n^2 + c, z_0 = c$                                                                     |

## 🎮 Controls

The program supports the following controls:

| Key           | Description                             |
|:-------------:|:---------------------------------------:|
| ESC           | Close the program window                |
| Mouse Scroll  | Zoom in and out of the fractal          |
| ⬆️ ⬇️ ⬅️ ➡️     | Change the viewpoint                    |

## 👨‍💻 Usage
### Requirements

The program is written in C language and thus needs the **gcc compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the program**

To compile the program, run:

```shell
$ git clone https://github.com/RogerioLS/Fractol-42sp/tree/main && cd Fractol-42sp && make
```

**2. How to run the program**

Run the executable too see the help message:
```shell
./fractol

Please enter: 
        "./fractol mandelbrot" or 
        "./fractol tricorn" or 
        "./fractol julia 0.285 +0" 
        "./fractol julia 0.285 +0.01" 
        "./fractol julia 0.45 +0.1428" 
        "./fractol julia -0.835 -0.232" 
        "./fractol julia −0.7269 +0.1889" 
        "./fractol julia 0.35 +0.35" 
        "./fractol julia 0.4 +0.4"
```

> [!NOTE]  
> Because of 42 School norm requirements:
> * Each function can't have more than 25 lines of code.
> * All variables are declared and aligned at the top of each function.
> * Project should be created just with allowed functions otherwise it's cheating.