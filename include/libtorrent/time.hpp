/*

Copyright (c) 2007-2016, Arvid Norberg
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the distribution.
    * Neither the name of the author nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef TORRENT_TIME_HPP_INCLUDED
#define TORRENT_TIME_HPP_INCLUDED

#include "libtorrent/config.hpp"

#include "libtorrent/aux_/disable_warnings_push.hpp"

#include <boost/cstdint.hpp>

#include <chrono>

#if defined TORRENT_BUILD_SIMULATOR
#include "simulator/simulator.hpp"
#endif

#include "libtorrent/aux_/disable_warnings_pop.hpp"

namespace libtorrent {

#if defined TORRENT_BUILD_SIMULATOR
	using clock_type = sim::chrono::high_resolution_clock;
#else
	using clock_type = std::chrono::high_resolution_clock;
#endif

	using time_point = clock_type::time_point;
	using time_duration = clock_type::duration;

	using std::chrono::seconds;
	using std::chrono::milliseconds;
	using std::chrono::microseconds;
	using std::chrono::minutes;
	using std::chrono::hours;
	using std::chrono::duration_cast;

	// internal
	inline time_point min_time() { return (time_point::min)(); }

	// internal
	inline time_point max_time() { return (time_point::max)(); }

	template<class T>
	boost::int64_t total_seconds(T td)
	{ return duration_cast<seconds>(td).count(); }

	template<class T>
	boost::int64_t total_milliseconds(T td)
	{ return duration_cast<milliseconds>(td).count(); }

	template<class T>
	boost::int64_t total_microseconds(T td)
	{ return duration_cast<microseconds>(td).count(); }

}

#endif // TORRENT_TIME_HPP_INCLUDED

