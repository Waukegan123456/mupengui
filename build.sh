#!/bin/bash
rm *.build *.changes *.diff.gz *.dsc
mv mupengui-0.1/debian .
rm -rf mupengui-0.1/obj-x86_64-linux-gnu
rm -rf mupengui-0.1/debian/mupengui
rm mupengui-0.1/mupengui
rm mupengui-0.1/Makefile
tar -czf mupengui_0.1.orig.tar.gz mupengui-0.1
mv debian mupengui-0.1
cd mupengui-0.1
debuild
# debuild -kYOURKEY
