#ifndef __BASE_STATE_GPP_INCLUDED__
#define __BASE_STATE_GPP_INCLUDED__

namespace Core
{
	class base_state
	{
	public:
		virtual void init() = 0;

		virtual void update() = 0;
		virtual void draw() = 0;

		virtual void puase() = 0;
		virtual void resume() = 0;
	};
} // namespace Core

#endif /* !__BASE_STATE_GPP_INCLUDED__ */