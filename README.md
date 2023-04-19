# miniRT

Discover my miniRT, a simple CPU-based raytracer.

## How to use ?
This program is compatible with Mac and Linux based systems  
Just clone the repo and run the ```installer.sh``` script:  
```
git clone https://github.com/leonardkrief/miniRT
cd miniRT
sh installer.sh
```

The executable miniRT will be generated and you will be able to load any scene in it: ```./miniRT path_to_scene```  
For example
```
./miniRT maps/ra.rt
```

## Creating a scene

A scene is a file containing all of the objects that will load into your raytracer. It's extension MUST BE ```.rt```  
In that file will be mentionned 2 types of objects: special objects, and shapes.  
Special objects are the *Ambient Lightning*, the *Camera* and the *Lights*  
Available shapes are *spheres*, *plans* and *cylinders*  
Below is a detailed manual for every objects you can mention in your scenes
***

> ### Special objects
<details>
<summary> Camera (must be unique) </summary>
```
C xPos,yPos,zPos xDir,yDir,zDir   FOV
```
`Pos` is the camera position point.

`Dir` is the camera orientation vector.

`FOV` is the field of view.
</details>

<details>
<summary> Ambient light (must be unique) </summary>

```
A   Ratio   R,G,B
```

`Ratio` is the intensity of the light, in range `[0;1]`.

`R,G,B` is the color of the ambient light, each component is in range `[0;255]`. 
</details>

<details>
<summary>Lights (up to 10)</summary>
```
L   xPos,yPos,zPos   Ratio   R,G,B
```

`Pos` is the light position point.

`Ratio` is the intensity of the light, in range `[0;1]`.

`R,G,B` is the color of the light, each component is in range `[0;255]`. 
</details>

***

> ### Geometric shapes (no theoretical limitation)
<details>
<summary>Sphere :</summary>

```
sp    xPos,yPos,zPos    Radius    R,G,B
```

`Pos` is a point describing the sphere position.

`R,G,B` is the color of the sphere, each component is between range `[0;255]`. 

`Radius` is the radius of the sphere.
</details>

<details>
	<summary>Plane:</summary>

```
pl    xPos,yPos,zPos    xDir,yDir,zDir    R,G,B
```

`Pos` is a point describing the plane position.

`Dir` is a vector orienting the plane.

`R,G,B` is the color of the plane, each component is between range `[0;255]`. 
</details>

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

***

> ### Patterns
My ray-tracer supports several patterns but they are not handled in the parsing of the scenes. I will try to add that later :)

### Until then, enjoy and have fun
