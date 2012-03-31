//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// Copyright (C) 2011 Vicente J. Botet Escriba
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// <future>

// class promise<R>

// promise(promise&& rhs);

#define BOOST_THREAD_VERSION 2
#define BOOST_THREAD_FUTURE_USES_ALLOCATORS

#include <boost/thread/future.hpp>
#include <boost/detail/lightweight_test.hpp>

boost::mutex m;

int main()
{
  {
      typedef int T;
      boost::promise<T> p;
      boost::future<T> f0 = p.get_future();
      boost::future<T> f = boost::move(f0);
      BOOST_TEST(!f0.valid());
      BOOST_TEST(f.valid());
  }
  {
      typedef int T;
      boost::future<T> f0;
      boost::future<T> f = boost::move(f0);
      BOOST_TEST(!f0.valid());
      BOOST_TEST(!f.valid());
  }
  {
      typedef int& T;
      boost::promise<T> p;
      boost::future<T> f0 = p.get_future();
      boost::future<T> f = boost::move(f0);
      BOOST_TEST(!f0.valid());
      BOOST_TEST(f.valid());
  }
  {
      typedef int& T;
      boost::future<T> f0;
      boost::future<T> f = boost::move(f0);
      BOOST_TEST(!f0.valid());
      BOOST_TEST(!f.valid());
  }
  {
      typedef void T;
      boost::promise<T> p;
      boost::future<T> f0 = p.get_future();
      boost::future<T> f = boost::move(f0);
      BOOST_TEST(!f0.valid());
      BOOST_TEST(f.valid());
  }
  {
      typedef void T;
      boost::future<T> f0;
      boost::future<T> f = boost::move(f0);
      BOOST_TEST(!f0.valid());
      BOOST_TEST(!f.valid());
  }

  return boost::report_errors();
}

