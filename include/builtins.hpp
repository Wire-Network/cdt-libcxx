#pragma once

#include <cstdio>
#include <type_traits>
/*
template<class T> T __sync_fetch_and_add(T* ptr, T val) {
   T old = *ptr;
   *ptr += typename std::conditional<std::is_pointer<T>::value, size_t, T>::type( val );
   return old;
}

template<class T> T __sync_add_and_fetch(T* ptr, T val) {
   return ptr += typename std::conditional<std::is_pointer<T>::value, size_t, T>::type( val );
}

template<class T> T __sync_lock_test_and_set(T* ptr, T val) {
   T old = *ptr;
   *ptr = typename std::conditional<std::is_pointer<T>::value, size_t, T>::type( val );
   return old;
}
*/

inline int32_t __sync_lock_test_and_set( int32_t* ptr, int32_t val ) {
   auto old = *ptr;
   *ptr = val;
   return old;
}

inline int32_t __sync_fetch_and_add( int32_t* ptr, int32_t val ) {
   auto old = *ptr;
   *ptr += val;
   return old;
}

inline int32_t __sync_add_and_fetch( int32_t* ptr, int32_t val ) {
   return *ptr += val;
}

inline std::unexpected_handler __sync_lock_test_and_set( std::unexpected_handler* ptr, std::unexpected_handler val ) {
   auto old = *ptr;
   *ptr = val;
   return old;
}

inline std::unexpected_handler __sync_fetch_and_add( std::unexpected_handler* ptr, std::unexpected_handler val ) {
   auto old = *ptr;
   *reinterpret_cast<char*>( *ptr ) = size_t(val);
   return old;
}
