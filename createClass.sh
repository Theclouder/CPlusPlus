#!/bin/bash

red="\033[0;31m"
l_red="\033[1;31m"
green="\033[0;32m"
purple="\033[0;35m"
reset="\033[0m"

if [ $# -eq 0 -o $# -ge 2 ]
then
	echo "Insert a class name as argument"
	exit
fi

# ---	Hpp constructors	 --- #
header="#include <iostream>

class $1
{
"
first_part_hpp="
	public:
		$1();
		$1(const $1 &);
"
second_part_hpp=$'\t\t'
second_part_hpp+="$1& operator=(const $1 &);
		~$1();
"

last_part_hpp="
};
"

# ---	Cpp constructors	 --- #
cpp="#include \"$1.hpp\"
"
first_part_cpp="
$1::$1()"

second_part_cpp="
$1::$1(const $1 & rhs)"

third_part_cpp="
{
	*this = rhs;
}

$1& $1::operator=(const $1 & rhs)"
last_part_cpp="
$1::~$1() {}
"

# ---	Global vars	 --- #
idx=0
keep=0
class=$1
arr_val=( "" "" "" "" "" )
arr_sent=( "Enter property type:" "Enter property name:" "Is it a pointer or not?" "Is it const?" "Is it private or protected? [0/1]" )
arr_err=( "Enter 1/y for yes or 0/n for no" "Enter 1 for protected or 0 for private" )
declare -a all_vars
declare -a list_vars

default_cpp() {
	if [ ${#all_vars[@]} -ne 0 ]; then
		for ((i = 0; i <= idx; i++)); do
			arr=(${all_vars[$i]})
			if [ ${arr[3]} = "0" ]; then
				continue;
			else
				first_part_cpp+=" : "
				second_part_cpp+=" : "
				break;
			fi
		done
		check=0
		for ((i = 0; i <= idx; i++)); do
			arr=(${all_vars[$i]})
			if [ ${arr[3]} = "0" ]; then
				continue;
			fi
			if [ $check -eq 1 ]; then
				first_part_cpp+=", "
				second_part_cpp+=", "
			fi
			check=1
			if [ ${arr[2]} = "1" ]; then
				first_part_cpp+="_${arr[1]}(nullptr)"
			elif [ ${arr[0]} = "std::string" ]; then
				first_part_cpp+="_${arr[1]}(\"None\")"
			elif [ ${arr[0]} = "int" ]; then
				first_part_cpp+="_${arr[1]}(0)"
			else
				first_part_cpp+="_${arr[1]}(NULL)"
			fi
			second_part_cpp+="_${arr[1]}(rhs._${arr[1]})"
		done
	fi
	first_part_cpp+=$' {}\n'
}

operator_cpp() {
	if [ ${#all_vars[@]} -ne 0 ]; then
		equal_op+=$'\n{'
		for ((i = 0; i <= idx; i++)); do
			arr=(${all_vars[$i]})
			if [ ${arr[3]} = "1" ]; then
				continue;
			fi
			equal_op+=$'\n\t'
			equal_op+="this->_${arr[1]} = rhs._${arr[1]};"
		done
		equal_op+=$'\n\treturn *this;'
		equal_op+=$'\n}\n'
	else
		equal_op+=$' {}'
	fi
}

get_set_cpp() {
	if [ ${#all_vars[@]} -ne 0 ]; then
		for ((i = 0; i <= idx; i++)); do
			arr=(${all_vars[$i]})
			tmp=$(echo "${arr[1]:0:1}" | tr a-z A-Z)${arr[1]:1}
			get_set_cpp+=$'\n'
			if [ ${arr[3]} = "1" ]; then
				get_set_cpp+="const "
			fi
			get_set_cpp+="${arr[0]} $class::get${tmp}() const"
			get_set_cpp+=$'\n{\n\t'
			get_set_cpp+="return this->_${arr[1]};"
			get_set_cpp+=$'\n}\n'
		done
		for ((i = 0; i <= idx; i++)); do
			arr=(${all_vars[$i]})
			tmp=$(echo "${arr[1]:0:1}" | tr a-z A-Z)${arr[1]:1}
			if [ ${arr[3]} = "1" ]; then
				continue;
			fi
			get_set_cpp+=$'\n'
			get_set_cpp+="void $class::set${tmp}(${arr[0]} "
			if [ ${arr[2]} = "1" ]; then
				get_set_cpp+=$'* '
			else
				get_set_cpp+=$'& '
			fi
			get_set_cpp+="${arr[1]})"
			get_set_cpp+=$'\n{\n\t'
			get_set_cpp+="this->_${arr[1]} = ${arr[1]};"
			get_set_cpp+=$'\n}\n'
		done
	fi
}

get_set_hpp() {
	if [ ${#all_vars[@]} -ne 0 ]; then
		for ((i = 0; i <= idx; i++)); do
			get_set_hpp+=$'\n\t\t'
			arr=(${all_vars[$i]})
			if [ ${arr[3]} = "1" ]; then
				get_set_hpp+=$'const '
			fi
			get_set_hpp+="${arr[0]}"
			if [ ${arr[2]} = "1" ]; then
				get_set_hpp+=$'* '
			else
				get_set_hpp+=$' '
			fi
			tmp=$(echo "${arr[1]:0:1}" | tr a-z A-Z)${arr[1]:1}
			get_set_hpp+="get${tmp}() const;"
		done
		for ((i = 0; i <= idx; i++)); do
			get_set_hpp+=$'\n\t\t'
			arr=(${all_vars[$i]})
			if [ ${arr[3]} = "1" ]; then
				continue;
			fi
			get_set_hpp+="void "
			tmp=$(echo "${arr[1]:0:1}" | tr a-z A-Z)${arr[1]:1}
			get_set_hpp+="set${tmp}("
			get_set_hpp+="${arr[0]}"
			if [ ${arr[2]} = "1" ]; then
				get_set_hpp+=$' *'
			else
				get_set_hpp+=$' &'
			fi
			get_set_hpp+=");"
		done
	fi
}

custom_constr_cpp() {
	if [ ${#all_vars[@]} -ne 0 ]; then
		custom_constr_cpp=$'\n'
		custom_constr_cpp+="$class::$class("
		for ((i = 0; i <= idx; i++)); do
			arr=(${all_vars[$i]})
			custom_constr_cpp+=$'const '
			custom_constr_cpp+="${arr[0]} "
			if [ ${arr[2]} = "1" ]; then
				custom_constr_cpp+=$'* '
			fi
			custom_constr_cpp+="${arr[1]}"
			if [ $i -ne $idx ]; then
				custom_constr_cpp+=", "
			fi
		done
		custom_constr_cpp+=") : \\"
		custom_constr_cpp+=$'\n\t'
		for ((i = 0; i <= idx; i++)); do
			arr=(${all_vars[$i]})
			custom_constr_cpp+="_${arr[1]}(${arr[1]})"
			if [ $i -ne $idx ]; then
				custom_constr_cpp+=", "
			fi
		done
		custom_constr_cpp+=$' {}'
	fi
	custom_constr_cpp+=$'\n'
}

custom_constr_hpp() {
	if [ ${#all_vars[@]} -ne 0 ]; then
		custom_constr_hpp=$'\t\t'
		custom_constr_hpp+="$class("
		for ((i = 0; i <= idx; i++)); do
			arr=(${all_vars[$i]})
			if [ ${arr[3]} = "1" ]; then
				custom_constr_hpp+=$'const '
			fi
			custom_constr_hpp+="${arr[0]}"
			if [ ${arr[2]} = "1" ]; then
				custom_constr_hpp+=$'*'
			fi
			if [ $i -ne $idx ]; then
				custom_constr_hpp+=", "
			fi
		done
		custom_constr_hpp+=$');'
	fi
	custom_constr_hpp+=$'\n'
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
	export IFS="@"
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
#	echo -e "$vars"
#	echo
#	for i in "${list_vars[@]}"; do
#		echo "${i}"
#	done
#	echo
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
	local loop=true
	while $loop; do
		if [ $keep -eq 4 ]; then
			res=""
			for i in {0..4}; do
				res+="${arr_val[$i]}@"
			done
			all_vars[$idx]=$res
			echo -e -n "${purple}Do you want to add another property? [Y/n] "
			read check
			echo -e -n $reset
			if [ -z $check ] || [ $check = "Y" -o $check = "y" ]; then
				keep=0
				((idx++))
				return 1
			elif [ $check = "N" -o $check = "n" ]; then
				return 2
			else
				echo -e "$red${arr_err[0]}"
				check=""
			fi
		else
			loop=false
		fi
	done
	return 0
}

echo -e -n "${purple}Do you want to add some properties? [Y/n] "
read ans
if [ -z "$ans" ] || [ $ans = "Y" -o $ans = "y" ]; then
	while [ $keep -lt 5 ]; do
		echo -e -n "$purple${arr_sent[$keep]} "
		read val
		if [ $? == 1 ]; then
			exit
		elif [[ "${val}" =~ [^a-zA-Z] ]] && [ $keep -lt 2 ]; then
			echo -e "${red}Variable name and type can contain only letters"
			continue ;
		fi
		echo -e -n $reset
		if [ -z $val ]; then
			echo -e -n "${l_red}Exit? "
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
#for ((i = 0; i <= idx; i++)); do
#	echo "${all_vars[$i]}"
#done

add_variables
custom_constr_hpp
get_set_hpp
operator_cpp
custom_constr_cpp
get_set_cpp
default_cpp
out_hpp="$header$vars$first_part_hpp$custom_constr_hpp$second_part_hpp$get_set_hpp$last_part_hpp"
out_cpp="$cpp$first_part_cpp$second_part_cpp$third_part_cpp$equal_op$custom_constr_cpp$last_part_cpp$get_set_cpp"
#echo "OUT HPP: $out_hpp"
#echo "OUT CPP: $out_cpp"
#exit
cat > $1.hpp << EOF
$out_hpp
EOF
cat > $1.cpp << EOF
$out_cpp
EOF
echo -e "${green}Class $1 created!"
