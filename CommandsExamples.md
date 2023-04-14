**Commands And Examples**
- On this section you will find some examples of how to use some of the algorithms and  and their outputs as well.</br></br>
   **Reading an Image**</br></br>
   **Input Image**</br>
   ![alt text](ImageProcessingCPP/image2.png "Input Image")</br></br>
   ```
   Image imag("image2.png");//by the Image source
   ```
   **Constrast Stretching**</br>
   ```
   Image image_cont = imag.ContrastStretch();
   image_cont.display(); //displaying the image
   image_cont.save(); //saving the image
   ```
    **Output**</br>
   ![alt text](ImageProcessingCPP/image2-Constrast_Stretch.png "Output-Contrast Stretching")</br></br>
   
   **Median filter**</br>
   **Input**</br>
   ![alt text](ImageProcessingCPP/saltPe_noise.png "Input-saltPe_noise")</br></br>
   
   ```
   Image image_med = imag.median();
   image_med.display();
   image_med.save();
   ```
   **Output**</br>
   ![alt text](ImageProcessingCPP/saltPe_noise-Median_filter.png "Output-Median Filter")</br>
   
   **Edge Detection**</br>
   ```
   Image imagX = imag.edgeDetect("sobelX"); // Sobel By dx
   imagX.display();
   imagX.save();
   
   Image imagY = imag.edgeDetect("sobelY");//Sobel By dy
   imagY.display();
   imagY.save();

   Image imagM = imag.edgeDetect("sobelM");//Sobel magnitude
   imagM.display();
   imagM.save();
   
   Image imagL = imag.edgeDetect("laplac");
   imagL.display();
   imagL.save();
   ```
   **Outputs:**</br></br>
   **SobelX:**</br>
   ![alt text](ImageProcessingCPP/image2-sobelX.png "Output-SobelX")</br></br>
   **SobelY:**</br>
   ![alt text](ImageProcessingCPP/image2-sobelY.png "Output-SobelY")</br></br>
   **SobelM:**</br>
   ![alt text](ImageProcessingCPP/image2-SobelM.png "Output-SobelM")</br></br>
   **Laplac:**</br>
   ![alt text](ImageProcessingCPP/image2-laplac.png "Output-Laplac")</br></br>
   
   **Corner Detection**</br>
   **Input**</br>
   ![alt text](ImageProcessingCPP/image7.jpg "Input-Corners")</br></br>
   
   ```
   Image imag2 = imag.corners();
   imag2.display();
   imag2.save();
   ```
   **Output**</br>
   ![alt text](ImageProcessingCPP/image7-Corners.jpg "Output-Corners")</br></br>
