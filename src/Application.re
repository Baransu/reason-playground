let component = ReasonReact.statelessComponent("Application");

let make = _children => {
  ...component,
  render: _self =>
    <ReasonApollo.Provider client=Client.instance>
      <div>
        <User login="baransu">
          ...(
               user =>
                 Option.getOrElse("Use has no bio", user##bio)
                 |> ReasonReact.string
             )
        </User>
      </div>
    </ReasonApollo.Provider>,
};