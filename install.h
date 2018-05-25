which zypper &> /dev/null && os="opensuse"
which pacman &> /dev/null && os="archlinux"
which dnf &> /dev/null && os="fedora"
which apt-get &> /dev/null && os="debian"
which emerge &> /dev/null && os="gentoo"

case "$os" in
    opensuse)
	zypper update
	zypper install freeglut3-dev
	zypper install libxcursor-dev
	zypper install libx11-dev
	;;
    archlinux)
	pacman -Syu
	pacman -S freeglut3-dev
	pacman -S install libxcursor-dev
	pacman -S install libx11-dev
	;;
    fedora)
	dnf update
	dnf install freeglut3-dev
	dnf install libxcursor-dev
	dnf install libx11-dev
	;;
    debian)
	apt-get update; sudo apt-get upgrade
	apt-get install freeglut3-dev
	apt-get install libxcursor-dev
	apt-get install libx11-dev
	;;
    gentoo)
	emerge -u world
	apt-get install freeglut3-dev
	apt-get install libxcursor-dev
	apt-get install libx11-dev
	;;
    esac
