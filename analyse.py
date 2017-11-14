#!/usr/bin/env python3
import sys
import re


if(len(sys.argv)>1):
	contient_a=re.search("a",sys.argv[1])
	contient_p=re.search("p",sys.argv[1])

	if(contient_a or contient_p):
		if(contient_a):
			print("Option a !!")
		if(contient_p):
			print("Option p !!")
	else:
		print("Attention : les options spécifiées sont incorrectes")

else:
	print("Aucune option spécifiée")
