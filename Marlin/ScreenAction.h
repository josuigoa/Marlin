#ifndef SCREEN_ACTION_H
#define SCREEN_ACTION_H

#include <stdint.h>

#include "Screen.h"
#include "Functor.h"

namespace screen
{
   template <typename R, typename... Args>
		class ScreenAction : public Screen, public Functor<R, Args...>
	{
		public:
			ScreenAction(const char * title = 0, typename Functor<R, Args...>::FuncPtr fptr = do_nothing);
			virtual ~ScreenAction();
	};

	template <typename R, typename... Args>
	ScreenAction<R, Args...>::ScreenAction(const char * title, typename Functor<R, Args...>::FuncPtr fptr)
		: Screen(title, ACTION)
		, Functor<R, Args...>(fptr)
	{ }

	template <typename R, typename... Args>
	ScreenAction<R, Args...>::~ScreenAction()
	{ }
}

#endif //SCREEN_ACTION_H