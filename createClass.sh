#!/bin/bash

if [ $# -eq 0 -o $# -ge 2 ]
then
	echo "Insert a class name as argument"
	exit
fi

echo -n "Do you want to have some properties? [Y/n] "
read ans

idx=0
keep=0
arr_val=( "" "" "" "" "" )
arr_sent=( "Enter property type: " "Enter property name: " "Is it a pointer or not? " "Is it const? " "Is it private or protected? [0/1]" )
declare -a arr_val
declare -a all_vars

if [ -z "$ans" ] || [ $ans = "Y" ]
then
	while [ $keep -lt 5 ]
	do
		echo ${arr_sent[$keep]}
		read val
		if [ -z $val ]
		then
			read -s -p "Don't you want to add a property? [N/y] " check
			if [ -z "$check" ] || [ $check = "N" -o $check = "n" ]
			then
				break ;
			else
				keep=0;
				continue ;
			fi
		fi
		arr_val[$keep]=$val
		if [ $keep -eq 4 ]
		then
			all_vars[$idx]=$arr_val
			read -s -p "Do you want to add another property? [Y/n] " yes_no
			if [ -z $yes_no ] || [ $yes_no = "Y" ]
			then
				keep=0
				((idx++))
				continue ;
			else
				break ;
			fi
		fi
		((keep++))
	done
fi
echo
for i in ${all_vars[@]}
do
	echo -e "$i \n"
done
exit

cat > $1.hpp << EOF
#include <iostream>

class $1
{
	private:
	
	public:
		$1();
		$1(const $1 &);
		$1& operator=(const $1 &);
		~$1();
};
EOF

cat > $1.cpp << EOF
#include "$1.hpp"

$1::$1() {}

$1::$1(const $1 & rhs)
{
	*this = rhs;
}

$1& $1::operator=(const $1 & rhs)
{

}

$1::~$1() {}
EOF
