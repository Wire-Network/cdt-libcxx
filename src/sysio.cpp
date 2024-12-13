#pragma once

/**
 * Define specific things for the sysio system
 */

extern "C" {
   void sysio_assert(unsigned int, const char*);
   void __cxa_pure_virtual() { sysio_assert(false, "pure virtual method called"); }
}
