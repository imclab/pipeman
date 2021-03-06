#pragma once

/// <summary>
/// This is the control block that occupies the first 256 bytes of the shared section.
/// The control block enables descriptive information about the communications link to
/// be stored and synchronized
/// </summary>
struct SCONTROLBLOCK
{
	union
	{
		struct
		{
			// Total number of bytes allocated, less the control block
			long long llAllocationSize;

			// The total size of individual buffers following on after the control header
			long long llBufferSize;

			// The total number of buffers allocated in this section
			long long llBufferCount;

			// This is the buffer where the reader is currently reading
			long long llReaderIndex;
			
			// This is the number of buffers currently in the queue:
			long long llQueueLength;

			// Set to true if this channel is stale
			bool bStale;
		};

		// Ensure that we've got the correct length:
		BYTE padding[256];
	};
};
static_assert(sizeof(SCONTROLBLOCK) == 256, "Control block must be exactly 256 bytes wide");