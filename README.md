# 42-miniRT

[![42](https://img.shields.io/badge/42-common_core-green.svg)](https://shields.io/)
[![42](https://img.shields.io/badge/Made%20in%20-C-blue.svg)](https://shields.io/)

Welcome to the world of raytracing ! Discover my miniRT, a simple CPU-based raytracer.

## Before reading
Note that I used a right-hand coordinate system, using the y-axis as the up vector and z-axis as the forward vector of our coordinate system.

## How to use ?
For full experience compile the bonus version using `make`.
Each map file must be terminated with the `.rt` extension.

```
git clone https://github.com/leonardkrief/miniRT
make
./miniRT path_to_file.rt
```

## Creating a scene

<details>
<summary> Camera (only one per file): </summary>

```
C xPos,yPos,zPos xDir,yDir,zDir   FOV
```
`Pos` is the camera position point.

`Dir` is the camera orientation vector.

`FOV` is the field of view.
</details>

***

<details>
<summary> Ambient light used to <i>simulate</i> indirect illumination (only one per file): </summary>

```
A   Ratio   R,G,B
```

`Ratio` is the intensity of the light, in range `[0;1]`.

`R,G,B` is the color of the ambient light, each component is in range `[0;255]`. 
</details>

***

<details>
<summary>Lights (no limitation):</summary>

```
L   xPos,yPos,zPos   Ratio   R,G,B
```

`Pos` is the light position point.

`Ratio` is the intensity of the light, in range `[0;1]`.

`R,G,B` is the color of the light, each component is in range `[0;255]`. 
</details>

***

**Each line starts with an identifier, describing a shape.**

My miniRT supports a couple of basic shapes :

* Sphere : `sp`
* Infinite plane : `pl`
* Finite closed cylinder : `cy`

***

<details>
<summary>Sphere :</summary>

```
sp    xPos,yPos,zPos    Radius    R,G,B
```

`Pos` is a point describing the sphere position.

`R,G,B` is the color of the sphere, each component is between range `[0;255]`. 

`Radius` is the radius of the sphere.
</details>

***

<details>
	<summary>Plane:</summary>

```
pl    xPos,yPos,zPos    xDir,yDir,zDir    R,G,B
```

`Pos` is a point describing the plane position.

`Dir` is a vector orienting the plane.

`R,G,B` is the color of the plane, each component is between range `[0;255]`. 
</details>

***

<details>
	<summary>Cylinder :</summary>

```
cy    xPos,yPos,zPos    xDir,yDir,zDir    Lenght    Diameter    R,G,B
```

`Pos` is a point describing the cylinder position.

`Dir` is a vector orienting the cylinder.

`R,G,B` is the color of the cylinder, each component is between range `[0;255]`. 

`Lenght` and `Diameter` cannot be negative.
</details>

My ray-tracer already supports several textures but I still need to code a way to parse them.
They are modifiable in the source code though. Check my main.c for examples :)
