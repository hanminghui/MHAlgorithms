echo "the files will be deleted:"
find . -type f -executable ! -path "./.git/*" ! -path "./ShellScripts/*" \
	   ! -path "./OS_tep/*"
echo "Do you want to delete them all?"
read answer
if [ $answer = "y" ]; then
	find . -type f -executable ! -path "./.git/*" ! -path "./ShellScripts/*" \
	   ! -path "./OS_tep/*" \
		-exec rm -v {} \;
else
	echo "you may delete them in another way"
fi
