# Developers Guide
## Code style
NEVER! use `#ifdef` or `#ifndef`.
Use `#if defined(...)` and `#if !defined(...)` instead.

## Difference between errno and function out
- Function output:
	- The value a function immediately sends back
	- What tells you something went wrong
- errno:
	- Detailed report
	- Why the error happened
