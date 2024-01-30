
# Adapter Pattern

<p align="center">
  <img src="pics/adapter.png" alt="Adapter Pattern" />
</p>

**What is it?**

A design pattern that lets incompatible interfaces work together.

**How?**

- **Adapter:** Connects two incompatible interfaces.
- **Target:** The interface you're adapting to.
- **Adaptee:** The interface being adapted.

**Example:**
`IDatabase` (target) and `WebAPI` (adaptee) are bridged by `WebAPIAdapter`.

**Use Cases:**

- Integrating new components with different interfaces.
- Working with legacy code.

**Benefits:**

- Simplifies interface compatibility.
- Enhances code flexibility and reusability.
