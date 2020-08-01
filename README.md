![Aquí la descripción de la imagen por si no carga](https://www.ups.edu.ec/ups_portal-theme/images/ups/home/logo-ups-home.png)
# Opencv-Project
Project Intercycle IA2
# Application developed in C++
In this application is doing to recognition objects.
### Hi there, We are Fernando Cusco and Ruben Abad👋
## We are  a Students, Classmates and Developer!
- 🔭 I’m currently working on a Text editor
- 🔭 He is currently working on a CLion
- 🌱 We are currently learning everything 🤣
- 👯 I’m looking to collaborate with other content creators
- 🥅 2020 Goals: Contribute more to Open Source projects

### Pre-requirements 📋
Install the required dependencies:
sudo apt install build-essential cmake git pkg-config libgtk-3-dev \
    libavcodec-dev libavformat-dev libswscale-dev libv4l-dev \
    libxvidcore-dev libx264-dev libjpeg-dev libpng-dev libtiff-dev \
    gfortran openexr libatlas-base-dev python3-dev python3-numpy \
    libtbb2 libtbb-dev libdc1394-22-dev

![Aquí la descripción de la imagen por si no carga](https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/306px-ISO_C%2B%2B_Logo.svg.png)

### You need to install   🔧

https://linuxize.com/post/how-to-install-opencv-on-ubuntu-18-04/

### Languages and Tools:
<img align="left" alt="C++" width="35px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/306px-ISO_C%2B%2B_Logo.svg.png" />
<img align="left" alt="CLion"  width="35px" src="https://cdn.worldvectorlogo.com/logos/clion-1.svg" />
<img align="left" alt="Text Editor"  width="35px" src="https://thumbs.dreamstime.com/b/text-editor-isolated-icon-simple-element-illustration-technology-concept-icons-editable-logo-sign-symbol-design-white-142287610.jpg" />
</br>
</br>
</br>

### System:
<img align="left" alt="Lubuntu Logo" width="150px" src="https://ubunlog.com/wp-content/uploads/2017/02/lubuntu.jpg" />
<img align="left" alt="Mac Logo"  width="80px" src="https://i.pinimg.com/originals/8e/fd/cf/8efdcf3106de0b15d3374f96d0af5246.png" />
</br>
</br>
</br>

### Git Stats:
<img  alt="Fernando-Cusco's Github Stats" src="https://github-readme-stats.vercel.app/api?username=Fernando-Cusco&show_icons=true&hide_border=true" />
<img  alt="RubenABAD25's Github Stats" src="https://github-readme-stats.vercel.app/api?username=RubenABAD25&show_icons=true&hide_border=true" />

### Modules doing to use:
#### COLOR_BGR2Lab:
L* for the lightness from black (0) to white (100), a* from green (−) to red (+), and b* from blue (−) to yellow (+).
This outputs 0≤L≤100, −127≤a≤127, −127≤b≤127 . The values are then converted to the destination data type:
•	8-bit images: L←L∗255/100,a←a+128,b←b+128
•	16-bit images: (currently not supported)
•	32-bit images: L, a, and b are left as is

#### CLAHE (Contrast Limited Adaptive Histogram Equalization):
So to solve this problem, adaptive histogram equalization is used. In this, image is divided into small blocks called "tiles" (tileSize is 8x8 by default in OpenCV). Then each of these blocks are histogram equalized as usual. So in a small area, histogram would confine to a small region (unless there is noise). If noise is there, it will be amplified. To avoid this, contrast limiting is applied. If any histogram bin is above the specified contrast limit (by default 40 in OpenCV), those pixels are clipped and distributed uniformly to other bins before applying histogram equalization.

#### Matche:
Helps us to draw the matches. It stacks two images horizontally and draw lines from first image to second image showing best matches.

#### Surf:
OpenCV provides SURF functionalities just like SIFT. You initiate a SURF object with some optional conditions like 64/128-dim descriptors, Upright/Normal SURF etc. All the details are well explained in docs. Then as we did in SIFT, we can use SURF.detect(), SURF.compute() etc for finding keypoints and descriptors.
#### BFMarcher:
Brute-Force matcher is simple. It takes the descriptor of one feature in first set and is matched with all other features in second set using some distance calculation.
#### Hu momnets:
Image moments are a weighted average of image pixel intensities.
#### Medianeblur
The function smoothes an image using the median filter with the  aperture. Each channel of a multi-channel image is processed independently. In-place operation is supported.
## Running of the Application ⚙️

### Doing to Test end-to-end 🔩

## Channel- Youtube 📖

You can find much more about how to use this project in our video [Video-Youtube](https://youtu.be/qvLOYSiZnyE)

## Conclusion ✒️

## Author ✒️

* **Ruben Abad** - *Developer 1* - [My person](https://www.facebook.com/rubaldo.labasca.5)
* **Fernando Cusco** - *Developer 2* - [ClassMates](https://www.facebook.com/fernando.cuscomejia)

## Teacher ✒️

* **Vladimir Robles**  (https://github.com/vlarobbyk)
## Expressions of gratitude 🎁

