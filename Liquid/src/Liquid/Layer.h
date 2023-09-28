#pragma once

#include "Liquid/Core.h"
#include "Liquid/Events/Event.h"

namespace Liquid {

	class LIQUID_API Layer 
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

		protected:
			std::string m_DebugName;
	};
}