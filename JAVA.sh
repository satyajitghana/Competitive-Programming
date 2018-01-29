#!/usr/bin/env bash

echo -n "Enter the Problem CODE : "
read code_name

read -r -d '' code_txt <<"EOF"
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
imoprt java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class $code_name {
	public static void main(String [] args) {
		BufferedReader br = new BufferedRead(new InputStreamReader(System.in));
		int T = br
	}
}
EOF

touch $code_name.java
tee $code_name.java <<< $code_txt
