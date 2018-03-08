# eBrowser---An energy-efficient mobile Web interaction framework in mobile Web browsers

ebrowser, an energy-efficient and lightweight human interaction framework without degrading the user interaction experience in mobile Web browsers.

## Architecture of ebrowser

ebrowser comprises the remote cloud side and the local browser side. The cloud side leverages the user interaction data to train the personalized event rate model for each mobile device using the SVR technique. The browser side collects the user interaction data and controls its interaction event rate, in order to reduce the power consumption of mobile Web interactions without degrading the interaction experience.

![](https://github.com/ebrowser-cloud/ebrowser/raw/master/images/architecture.png)  

## Setup,Compiling and Configuration

The browser side of ebrowser framework is developed base on [The Chromium Projects](https://www.chromium.org). The project version is 56.

### 1.External Dependencies

Before using our framework, you should get the code of Chromium for Android first. The instructions of checking out, building,& running Chromium is [here](https://chromium.googlesource.com/chromium/src/+/master/docs/android_build_instructions.md).
