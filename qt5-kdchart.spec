Name:           qt5-kdchart
Version:        2.6.2
Release:        1
Summary:        A Qt tool for creating business and scientific charts
Source:         %{name}-%{version}.tar.gz
Source1:        %{name}-rpmlintrc
URL:            http://github.com/KDAB/KDChart
Group:          System/Libraries
License:        GPL-2.0+
BuildRoot:      %{_tmppath}/%{name}-%{version}-build
Vendor:         Klaralvdalens Datakonsult AB (KDAB)
Packager:       Klaralvdalens Datakonsult AB (KDAB) <info@kdab.com>

BuildRequires: cmake
%if %{defined suse_version}
BuildRequires:  libqt5-qtbase-devel libqt5-qtsvg-devel
%endif

%if %{defined fedora}
BuildRequires:  gcc-c++ qt5-qtbase-devel qt5-qtsvg-devel desktop-file-utils
%endif

%if %{defined rhel}
BuildRequires:  gcc-c++ qt5-qtbase-devel qt5-qtsvg-devel desktop-file-utils
%endif

%description
KDAB's KD Chart a tool for creating business and scientific charts.
It provides developers with a sophisticated way to customize layouts and
to design and manage large numbers of axes. KD Chart targets C++ programmers
who use Qt in their applications.

Authors:
--------
      Klaralvdalens Datakonsult AB (KDAB) <info@kdab.com>

%define debug_package %{nil}
%global __debug_install_post %{nil}

%package devel
Summary:        Development files for %{name}
Group:          Development/Libraries/C and C++
Requires:       %{name} = %{version}

%description devel
This package contains header files and associated tools and libraries to
develop programs using kdchart.

%prep
%setup -q

%build
touch .license.accepted
%if "%{_lib}"=="lib64"
QMAKE_ARGS="LIB_SUFFIX=64" ./configure.sh -shared -release -no-unittests -prefix %{buildroot}/usr
%else
./configure.sh -shared -release -prefix %{buildroot}/usr
%endif
%__make %{?_smp_mflags}

%post -p /sbin/ldconfig
%postun -p /sbin/ldconfig

%install
%make_install

%clean
%__rm -rf "%{buildroot}"

%files
%defattr(-,root,root)
%{_prefix}/share/doc/KDChart
%{_libdir}/libkdchart.so.*

%files devel
%defattr(-,root,root,-)
%dir %{_includedir}/KDChart
%{_includedir}/KDChart/*
%dir %{_includedir}/KDGantt
%{_includedir}/KDGantt/*
%{_libdir}/libkdchart.so

%changelog
* Mon Apr 22 2019 Allen Winter <allen.winter@kdab.com> 2.6.2
  2.6.2 final
