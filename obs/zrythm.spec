#
# spec file for package loopidity
#
# Copyright (c) 2012-2107 bill-auger bill-auger@programmer.net
#
# All modifications and additions to the file contributed by third parties
# remain the property of their copyright owners, unless otherwise agreed
# upon. The license for this file, and modifications and additions to the
# file, is the same license as for the pristine package itself (unless the
# license for the pristine package is not an Open Source License, in which
# case the license is the MIT License). An "Open Source License" is a
# license that conforms to the Open Source Definition (Version 1.9)
# published by the Open Source Initiative.

# Please submit bugfixes or comments via http://bugs.opensuse.org/


Name:          zrythm
Version:       0.5.160
Release:       1%{?dist}
Summary: An highly automated, intuitive, Digital Audio Workstation (DAW)
License:       GPL-3.0
URL:           https://www.zrythm.org
Source0:       https://git.zrythm.org/zrythm/%{name}/-/archive/v%{version}/%{name}-v%{version}.tar.gz
BuildRequires: gcc-c++ gcc pkgconfig
BuildRequires: gtk3-devel python3
BuildRequires: lilv-devel
BuildRequires: lv2-devel
BuildRequires: libsndfile-devel
BuildRequires: libyaml-devel
BuildRequires: libsamplerate-devel
BuildRequires: gettext sed
BuildRequires: alsa-lib-devel
BuildRequires: ladspa-devel
BuildRequires: fftw-devel
BuildRequires: portaudio-devel
BuildRequires: meson
Requires: gtk3
Requires: ladspa
Requires: lilv libsamplerate
Requires: lv2
Requires: libyaml
Requires: libsndfile
Requires: alsa-lib
Requires: fftw
Requires: portaudio
%if 0%{?suse_version}
BuildRequires: jack-devel libX11-devel update-desktop-files
Requires:      jack
%endif
%if 0%{?fedora_version}
BuildRequires: jack-audio-connection-kit-devel libX11-devel qt5-devel
Requires:      jack-audio-connection-kit qt5
%endif
%if 0%{?mageia}
BuildRequires: libjack-devel libx11-devel qt5-devel
Requires:      jack qt5
%endif
%description
  Zrythm is a native GNU/Linux application built with
  the GTK+3 toolkit and using the JACK Connection Kit for audio I/O.
  Zrythm can automate plugin parameters using built in LFOs and envelopes
  and is designed to be intuitive to use.


%prep
%autosetup -n zrythm-v%{version}

%build
rm -rf build
%if 0%{?suse_version}
meson build --prefix=/usr -Denable_tests=true
%endif
%if 0%{?fedora_version}
# todo with qt5
meson build --prefix=/usr -Denable_tests=true
%endif
%if 0%{?mageia}
# todo with qt5
meson build --prefix=/usr -Denable_tests=true
%endif
ninja -C build

%install
DESTDIR="%{buildroot}/" ninja -C build install
%find_lang %{name}

%files
%defattr(-,root,root)
%license COPYING
%doc README.md CONTRIBUTING.md CHANGELOG.md
%{_bindir}/*
%{_datadir}/*

%post
%if ! 0%{?suse_version}
  xdg-desktop-menu forceupdate
%endif

%postun
%if ! 0%{?suse_version}
  xdg-desktop-menu forceupdate
%endif
%changelog
* Sun Jul 14 2019 Alexandros Theodotou
- v0.5.160
