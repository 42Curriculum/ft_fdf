# FDF

A program about making a wireframe and projection rendering.

This project is not "real" 3D, it is simply projection from a 2D map (the program input). Since it isn't complex ( and I was a bit lazy), I didn't use a projection matrix, instead I just simplified said projection matrix into two formulas.
<br> <img align="right" height="300" src="https://github.com/42Curriculum/ft_fdf/blob/master/resources/fdf.PNG"/><br>

Usage : ./fdf [fdf_map]

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

![](resources/42gif.gif)
