# Game of Life

A version of John Conway's classic Game of Life, written in C.

GVSU CIS 343, Winter 2019, Professor Woodring

Author(s):  Josh Weinmann and Daniel Shamburger

This program saves and loads games using the following format: 
The first byte of the file is the height. The second byte of the file is the width. The remaining bytes of the file are either zeros or ones, where a one is a live cell and a zero is no cell. Unlike some versions we will not keep track of where a cell was when it died; i.e. when a cell dies it is just gone. If the height of the file is h and the width is w, the total size of the file in bytes would then be (h x w) + 2.