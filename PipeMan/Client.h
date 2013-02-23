#pragma once
#include "Endpoint.h"

using namespace System;

namespace PipeMan
{
	public ref class Client:
		public Endpoint
	{
	public:
		Client(String^ name);
		
		// Inherited properties:
		property long long Available {virtual long long get(void) override;}

	public:
		/// <summary>
		/// Makes the current endpoint point to a filled buffer from the writer.  This MUST be called
		/// BEFORE the first attempt to read from the stream.
		/// </summary>
		virtual bool Flip(int timeout) override;
	};
}
