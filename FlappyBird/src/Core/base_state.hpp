#ifndef __BASE_STATE_GPP_INCLUDED__
#define __BASE_STATE_GPP_INCLUDED__

namespace Core
{
	class base_state
	{
	public:
		virtual void init() = 0;

		virtual void handleEvents() = 0;
		virtual void update(const float dt) = 0;
		virtual void draw(const float dt) = 0;

		virtual void pause() {};
		virtual void resume() {};
	};
} // namespace Core

#endif /* !__BASE_STATE_GPP_INCLUDED__ */