# FDF

A program about making a wireframe and projection rendering.

This project is not "real" 3D, it is simply projection from a 2D map (the program input). Since it isn't complex , I didn't use a projection matrix, instead I just simplified said projection matrix into two formulas.

**This program is foramtted according to the Norm (42's code guidelines). The requirements at the time were:
  - 25 lines per function
  - 5 or less functions per file
  - no multi line macros
  - 4 or less arguments per function
  - 5 or less variables per function
  - no for loops
  - 80 character or less per line
  - declaration of variables must be saparate from initialization
  - and more...

<br> <img align="right" height="300" src="https://github.com/42Curriculum/ft_fdf/blob/master/resources/fdf.PNG"/><br>


Usage : ./fdf [fdf_map]

![](resources/42gif.gif)

### Controls

- View mode : 

```
  [Arrows keys] Rotate
  [Scrollwheel] Zoom in/out
  [WASD  keys ] Move
  [Enter key  ] Switch to Edit mode
```

- Edit mode

```
  [Arrows keys] Select vertex
  [Scrollwheel] Zoom in/out
  [WASD  keys ] Move vertex
  [Space key  ] Saves map in fdf_maps folder
  [Enter key  ] Switch to View mode
```



**This program uses MLX for rendering. This is not my library and belongs to 42. Using it was a requirement for this project**
