#ifndef __BASE_STATE_GPP_INCLUDED__
#define __BASE_STATE_GPP_INCLUDED__

namespace Core
{
	class BaseState
	{
	public:
		virtual void init() = 0;

		virtual void handleEvents() = 0;
		virtual void update(const float dt) = 0;
		virtual void draw(const float dt) = 0;
	};
} // namespace Core

#endif /* !__BASE_STATE_GPP_INCLUDED__ */