#ifndef RACELIBRARY_H
#define RACELIBRARY_H

#ifdef RACELIBRARY_EXPORTS
#define RACE_API __declspec(dllexport)
#else
#define RACE_API __declspec(dllimport)
#endif

#endif