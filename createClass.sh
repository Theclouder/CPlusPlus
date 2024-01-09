#!/bin/bash

red="\033[0;31m"
green="\033[0;32m"
purple="\033[0;35m"
reset="\033[0m"

if [ $# -eq 0 -o $# -ge 2 ]
then
	echo "Insert a class name as argument"
	exit
fi

header="#include <iostream>

class $1
{
"
first_part_const="
	public:
		$1();
		$1(const $1 &);"
second_part_const="
		$1& operator=(const $1 &);
		~$1();
};
"

idx=0
keep=0
arr_val=( "" "" "" "" "" )
arr_sent=( "Enter property type:" "Enter property name:" "Is it a pointer or not?" "Is it const?" "Is it private or protected? [0/1]" )
arr_err=( "Enter 1/y for yes or 0/n for no" "Enter 1 for protected or 0 for private" )
declare -a all_vars
declare -a list_vars

create_custom_constr() {
	echo HOla
}

print_vars() {
	for ((i = 0; i <= idx; i++)); do
		arr=(${all_vars[$i]})
		local my_var=""
		if [ $var_type -eq 0 -a ${arr[4]} = "0" ] || [ $var_type -eq 1 -a ${arr[4]} = "1" ] ; then
			vars+=$'\t\t'
			if [ ${arr[3]} = "1" ]; then
				my_var+=$'const '
			fi
			my_var+="${arr[0]}"
			if [ ${arr[2]} = "1" ]; then
				my_var+=$'* '
			else
				my_var+=$' '
			fi
			my_var+="_${arr[1]};"
			my_var+=$'\n'
			if [ $var_type -eq 0 ]
			then
				list_vars[$i]=$my_var
				list_vars[$i]=${list_vars[$i]%?}
			else
				list_vars[$i+$idx]=$my_var
				list_vars[$i+$idx]=${list_vars[$i+$idx]%?}
			fi
			vars+=$my_var
		fi
	done
}

add_variables() {
	local prv=0
	local prt=0
	export IFS=","
	if [ ${#all_vars[@]} -eq 0 ]; then
		return 0
	fi
	for ((i = 0; i <= idx; i++)); do
		arr=(${all_vars[$i]})
		if [ ${arr[4]} = "0" ]; then
			prv=1
		elif [ ${arr[4]} = "1" ]; then
			prt=1
		fi
	done
	if [ $prv -ne 0 ]; then
		var_type=0
		vars+=$'\tprivate:\n'
		print_vars
	fi
	vars+=$'\n'
	if [ $prt -ne 0 ]; then
		var_type=1
		vars+=$'\tprotected:\n'
		print_vars
	fi
	echo -e "$vars"
	echo
	for i in "${list_vars[@]}"; do
		echo "${i}"
	done
	echo
}

check_value() {
	case $keep in
		0)
			if [ $val = "string" ]; then
				val="std::string"
			fi ;;
		2|3)
			case $val in
				"0"|"n")
					val="0"
					;;
				"1"|"y")
					val="1"
					;;
				*)
					echo -e "$red${arr_err[0]}$reset"
					return 1
					;;
			esac ;;
		4)
			case $val in
				"0")
					val="0"
					;;
				"1")
					val="1"
					;;
				*)
					echo -e "$red${arr_err[1]}$reset"
					return 1
					;;
			esac ;;
	esac
	return 0
}

refill_array() {
	if [ $keep -eq 4 ]; then
		res=""
		for i in {0..4}; do
			res+="${arr_val[$i]},"
		done
		all_vars[$idx]=$res
		echo -e -n "${purple}Do you want to add another property? [Y/n] "
		read check
		echo -e -n $reset
		if [ -z $check ] || [ $check = "Y" -o $check = "y" ]; then
			keep=0
			((idx++))
			return 1
		else
			return 2
		fi
	fi
	return 0
}

echo -e -n "${purple}Do you want to add some properties? [Y/n] "
read ans

if [ -z "$ans" ] || [ $ans = "Y" ]; then
	while [ $keep -lt 5 ]; do
		echo -e -n "$purple${arr_sent[$keep]} "
		read val
		echo -e -n $reset
		if [ $? == 1 ]; then
			echo
		fi
		if [ -z $val ]; then
			echo -e -n "Exit? "
			read check
			if [ -z "$check" ] || [ $check = "Y" -o $check = "y" ]; then
				break ;
			else
				keep=0;
				continue ;
			fi
		fi
		check_value; ec=$?
		if [ $ec -eq 1 ]; then
			continue;
		fi
		arr_val[$keep]=$val
		refill_array; ec=$?
		case $ec in
			1)
				continue;;
			2)
				break;
		esac
		((keep++))
	done
fi
for ((i = 0; i <= idx; i++)); do
	echo "${all_vars[$i]}"
done

add_variables
out="$header$vars$first_part_const$custom_const$second_part_const"
cat > $1.hpp << EOF
$out
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
