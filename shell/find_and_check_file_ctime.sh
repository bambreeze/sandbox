#echo $USER
my_passwd="ABCDEF"
my_output=`find . -name "*.txt" -type f -mtime -1`
#my_output=$(find . -name "*.txt" -type f -mtime -1)
echo $my_output | grep txt > /dev/null
if [ $? -eq 0 ]
then
    echo "find a txt file"
    echo $my_output
    rm -rf *.txt
else
    echo "need create a new txt file"
    rm -rf *.txt
    touch new_$USER_$my_passwd.txt
fi
